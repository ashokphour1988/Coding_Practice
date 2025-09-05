class TruckQueue {
public:
    int max;
    condition_variable cv;
    mutex m;
    TruckQueue(int n) {
        max = 0;
    }
   
    void enterWaitingArea(function<void()> leavingWaitingArea, int index) {
        int i = index;
        //cout<<"add "<<index<<endl;
        unique_lock<mutex> ul(m);
        //cout<<"here "<<max<<endl;
        cv.wait(ul, [i,this]{return (i == (max+1)) ? true : false;});
        // Do not change or remove this line.
        leavingWaitingArea();
        //cout<<"Release "<<index<<endl;
        max++;
        cv.notify_all();
    }
};