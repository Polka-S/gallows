#include "logger.h"
#include "manager.h"

int main() {
    log_init("logs.txt", debug);
    run();
    logclose();

    return 0;
}