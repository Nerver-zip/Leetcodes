class Foo {
public:
    void first(std::function<void()> printFirst) {
        printFirst(); // Aqui não há dependência, executa o print

        firstDone.store(true); // Marca estado como concluído
        firstDone.notify_one(); // Acorda uma thread esperando nesse atomic
    }

    void second(std::function<void()> printSecond) {
        firstDone.wait(false); // Dorme enquanto firstDone == false

        printSecond();

        secondDone.store(true); // Marca segundo estágio concluído
        secondDone.notify_one(); // Acorda quem espera secondDone
    }

    void third(std::function<void()> printThird) {
        secondDone.wait(false); // Dorme enquanto secondDone == false

        printThird();
    }

private:
    std::atomic<bool> firstDone{false};
    std::atomic<bool> secondDone{false};
};