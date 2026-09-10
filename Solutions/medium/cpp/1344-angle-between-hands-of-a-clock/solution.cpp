class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;

        double h = static_cast<double>(hour);
        double m = static_cast<double>(minutes);

        double gain = m/60;
        h += gain;

        double hour_deg = (h * 30);
        double minutes_deg = (m * 6);

        return min(abs(hour_deg - minutes_deg), 360 - abs(hour_deg - minutes_deg));
    }
};