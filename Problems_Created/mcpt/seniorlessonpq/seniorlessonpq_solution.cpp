#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int N;
  cin >> N;
  priority_queue<int> existing;
  for (int i = 0; i < N; i++)
  {
    string instruction;
    cin >> instruction;
    if (instruction == "KING")
    {
      int top = existing.top();
      cout << top << endl;
    }
    else if (instruction == "ARRIVAL")
    {
      int num = 0;
      cin >> num;
      existing.push(num);
    }
    else
    {
      existing.pop();
    }
  }
  return 0;
}
