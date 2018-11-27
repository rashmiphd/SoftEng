#include <iostream>

using namespace std;

class NodeManager
{
  class State *current;
  public:
    NodeManager();
    void setCurrent(State *s)
    {
        current = s;
    }
    void idle();
    void sensing();
    void processing();
};

class State
{
  public:
    virtual void idle(NodeManager *m)
    {
        cout << "   already idle\n";
    }
    virtual void sensing(NodeManager *m)
    {
        cout << "   already sensing\n";
    }
    virtual void processing(NodeManager *m)
    {
        cout<<" already processing\n";
    }
};

void NodeManager::idle()
{
  current->idle(this);
}

void NodeManager::sensing()
{
  current->sensing(this);
}
void NodeManager::processing()
{
    current->processing(this);
}
class IDLE: public State
{
  public:
    IDLE()
    {
        cout << "   IDLE-constructor ";
    };
    ~IDLE()
    {
        cout << "   deconstructor-IDLE\n";
    };
    void sensing(NodeManager *m);
};

class SENSING: public State
{
  public:
    SENSING()
    {
        cout << "   Sensing-constructor ";
    };
    ~SENSING()
    {
        cout << "   deconstructor-Sensing\n";
    };
    void processing(NodeManager *m)
    {
        cout << "   going from sensing to processing";
        m->setCurrent(new IDLE());
        delete this;
    }
};
class PROCESSING: public State
{
  public:
    PROCESSING()
    {
        cout << "   Processing-constructor ";
    };
    ~PROCESSING()
    {
        cout << "   deconstructor-Processing\n";
    };
    void idle(NodeManager *m)
    {
        cout << "   going from processing to idle";
        m->setCurrent(new IDLE());
        delete this;
    }
};
void IDLE::sensing(NodeManager *m)
{
  cout << "   going from idle to sensing";
  m->setCurrent(new SENSING());
  delete this;
}

NodeManager::NodeManager()
{
  current = new IDLE();
  cout << '\n';
}

int main()
{
  void(NodeManager:: *ptrs[])() =
  {
    NodeManager::idle, NodeManager::sensing, NodeManager::processing
  };
  NodeManager fsm;
  int num;
  while (1)
  {
    cout << "Enter 0/1/2: ";
    cin >> num;
    (fsm.*ptrs[num])();
  }
}
