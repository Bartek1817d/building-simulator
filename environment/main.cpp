#include <DAO.h>
#include "Logger.h"

int main(int argc, char *argv[]) {
    logger::Logger LOG("main", logger::Target::CONSOLE);
    LOG.info("This is log");
}
