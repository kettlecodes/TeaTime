#ifndef MOCKUPFILESYSTEM_H
#define MOCKUPFILESYSTEM_H

#include "interfaces/backend-services/FileSystemInterface.h"


class MockupFileSystem : public FileSystemInterface {
public:

    MockupFileSystem();
    ~MockupFileSystem() override;
};

#endif // MOCKUPFILESYSTEM_H
