export module Subject;
import Observer;
import <iostream>;
import <string>;
import <vector>;

export class Subject {
  std::vector<Observer*> observers;

 public:
  Subject();
  void attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers();
  virtual ~Subject()=0;
};
