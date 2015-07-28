// ServerGroup.h, by Junteng Tan (1489763)
// lab 4a, The "ServerGroup" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

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
