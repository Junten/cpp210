// ServerGroup.cpp
// lab 4a, The "ServerGroup" program

#include "ServerGroup.h"

ServerGroup::ServerGroup(const int& arg) {
  servers = new int[arg];
  for (int i = 0; i < arg; i++) {
    servers[i] = 0;
  }
  spServer = 0;
  size = arg;
}

bool ServerGroup::spServerFree() const {
  return (spServer == 0);
}

bool ServerGroup::serverFree() {
  bool isServerFree = false;
  for(int i=0; i < size; i++) {
    if(servers[i] == 0) {
      isServerFree = true;
      freeServer = i;
    }
  }
  return isServerFree;
}

void ServerGroup::useServer(const int& avTransTime) {
  servers[freeServer] = {avTransTime};
}

void ServerGroup::usespServer(const int& avTransTime) {
  spServer = avTransTime;
}

void ServerGroup::decServers() {
  if (spServer != 0) {
    spServer -= 1;
  }
  for (int i = 0; i < size; i++) {
    if (servers[i] != 0) {
      servers[i] -= 1;
    }
  }
}