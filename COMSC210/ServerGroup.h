// ServerGroup.h
// lab 4a, The "ServerGroup" program

#ifndef ServerGroup_H
#define ServerGroup_H
class ServerGroup{
public:
  ServerGroup(const int&);
  bool spServerFree(void) const;
  bool serverFree(void);
  void useServer(const int&);
  void usespServer(const int&);
  void decServers(void);
  
private:
  int* servers;
  int spServer;
  int freeServer;
  int size;
};
#endif
