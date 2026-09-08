class Solution {
private:
    class SegmentTree {
    private:
        int size = 1;
        vector<int> tree;

    public:
        SegmentTree() = default;

        explicit SegmentTree(const vector<int>& values) {
            while (size < static_cast<int>(values.size())) {
                size <<= 1;
            }

            tree.assign(2 * size, 0);

            for (int i = 0; i < static_cast<int>(values.size()); ++i) {
                tree[size + i] = values[i];
            }

            for (int i = size - 1; i >= 1; --i) {
                tree[i] = max(tree[2 * i], tree[2 * i + 1]);
            }
        }

        int query(int left, int right) const {
            if (left > right) {
                return 0;
            }

            left += size;
            right += size;

            int result = 0;

            while (left <= right) {
                if (left & 1) {
                    result = max(result, tree[left++]);
                }

                if (!(right & 1)) {
                    result = max(result, tree[right--]);
                }

                left >>= 1;
                right >>= 1;
            }

            return result;
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        const int n = static_cast<int>(s.size());
        const int totalOnes = count(s.begin(), s.end(), '1');

        vector<int> blockLeft;
        vector<int> blockRight;
        vector<int> blockLength;
        vector<int> zeroBlockId(n, -1);

        // Extract all maximal zero blocks.
        for (int i = 0; i < n;) {
            if (s[i] == '1') {
                ++i;
                continue;
            }

            const int left = i;

            while (i < n && s[i] == '0') {
                ++i;
            }

            const int right = i - 1;
            const int id = static_cast<int>(blockLength.size());

            blockLeft.push_back(left);
            blockRight.push_back(right);
            blockLength.push_back(right - left + 1);

            for (int position = left; position <= right; ++position) {
                zeroBlockId[position] = id;
            }
        }

        // First zero at or after each position.
        vector<int> nextZero(n + 1, n);

        for (int i = n - 1; i >= 0; --i) {
            nextZero[i] = (s[i] == '0' ? i : nextZero[i + 1]);
        }

        // Last zero at or before each position.
        vector<int> prevZero(n, -1);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                prevZero[i] = i;
            } else if (i > 0) {
                prevZero[i] = prevZero[i - 1];
            }
        }

        // Gain from merging consecutive global zero blocks.
        vector<int> pairGain;

        for (int i = 0; i + 1 < static_cast<int>(blockLength.size()); ++i) {
            pairGain.push_back(blockLength[i] + blockLength[i + 1]);
        }

        SegmentTree segmentTree(pairGain);

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            const int left = query[0];
            const int right = query[1];

            const int firstZero = nextZero[left];

            // The substring contains no zero block.
            if (firstZero > right) {
                answer.push_back(totalOnes);
                continue;
            }

            const int lastZero = prevZero[right];

            const int firstBlock = zeroBlockId[firstZero];
            const int lastBlock = zeroBlockId[lastZero];

            // Fewer than two zero blocks means no valid beneficial trade.
            if (firstBlock == lastBlock) {
                answer.push_back(totalOnes);
                continue;
            }

            const int leftClippedLength =
                min(blockRight[firstBlock], right) - firstZero + 1;

            const int rightClippedLength =
                lastZero - max(blockLeft[lastBlock], left) + 1;

            int bestGain = 0;

            if (lastBlock == firstBlock + 1) {
                bestGain =
                    leftClippedLength + rightClippedLength;
            } else {
                // Pair involving the left clipped block.
                bestGain = max(
                    bestGain,
                    leftClippedLength + blockLength[firstBlock + 1]
                );

                // Pair involving the right clipped block.
                bestGain = max(
                    bestGain,
                    blockLength[lastBlock - 1] + rightClippedLength
                );

                // Pairs containing two complete zero blocks.
                bestGain = max(
                    bestGain,
                    segmentTree.query(
                        firstBlock + 1,
                        lastBlock - 2
                    )
                );
            }

            answer.push_back(totalOnes + bestGain);
        }

        return answer;
    }
};