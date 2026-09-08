class MyCalendar {
private:
vector<pair<int,int>>events;
public:
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        bool flag=true;
        for(int i=0;i<events.size();++i)
        {
            int st=events[i].first;
            int et=events[i].second;
            if(s<=st && e>=et)
            {
                flag=false;
            }
           if(s>=st && e<=et)
           {
            flag=false;
           }
           if(s>=st && s<et && e>et)
           {
            flag=false;
           }
           if(s<st && e<=et && e>st)
           {
              flag=false;
           }
           if(e>et && s>st && s<et)
           {
            flag=false;
           }
           if(s<st && e>st && e<et)
           {
            flag=false;
           }

        }
      if(flag==true)
      {
        events.push_back({s,e});
        return true;
      }
         else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */