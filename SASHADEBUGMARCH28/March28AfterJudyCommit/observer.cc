export module Observer;
import <iostream>;
import <string>;
import <vector>;

export class Observer {
 public:
  virtual void notify() = 0;
  virtual ~Observer();
};
