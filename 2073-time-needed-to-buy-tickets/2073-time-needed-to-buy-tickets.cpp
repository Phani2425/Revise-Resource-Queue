class Solution {
    /* IN THIS APPROACH WE WILL DO THE SAME AS THE QUESTION HAS ASKED US TO DO.... MEANS WE WILL PUT TO ALL THE PERSON TO A QUEUE AND ACCORDING TO THE QUEUE WE WILL GIVE THEM TICKETS (REDUCE THEIR TICKET REQUIREMENTS BY 1) EACH TIME
    AND PUSH THEM AGAIN INTO THE QUEUE ONLY IF THEIR TICKET REQUIREMENT IS NOT 0 OTHERWISE WE'LL JUST POP THEM FROM QUEUE..... AND WE'LL DO THIS UNTILL "tickets[k]" BECOMES 0.....AND EACH TIME WE ALLOCATE ANYONE A TICKET WE'LL INCREASE TIME BY 1

    MOST IMPORATANT PART HERE IS TO THINK WHAT SHOULD WE INCLUDE IN QUEUE ????? INDEX VALUES(REPRESTING PERSON'S POSITION IN TICKET ARRAY) OR WE SHOULD INCLUDE VALUE OF "ticket[i]" IN QUEUE..... AND WHY SHOULD WE INCLUDE THAT IN QUEUE ????? */
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int size=tickets.size();
        int time=0;
        queue<int>q;
      for(int i=0;i<size;i++){
        q.push(i);
      }
      //giving them tickets
      while(tickets[k]){
        tickets[q.front()]--;
        time++;//time increment haba
        //adding them again in queue only if they require more than 0 ticket
        if(tickets[q.front()] != 0){
            q.push(q.front());
        } 
        //queue ra pachare add hau ki nahau ebe jie front re achi sie ticket neisarilani so sie baharaku bahariba
        q.pop();
      }


      return time;
    }
};

// APPROACH 1 (BRUTE FORCE APPROACH)

/* WE WILL TRAVERSE THE ARRAY "tickets" UNTILL THE THE VALUE AT KTH INDEX BECOMES 0 AND SIMULTANEOUSLY COUNT TIME
BUT HERE THE PROBLEM IS LET "ticket= {1,1,1,1,1,5}" AND IT HAS ASKED US TO FIND TIME REQUIRED FOR THE PERSON AT K=5 OR AT 5TH INDEX TO BUY ALL THE TICKETS.......
SO ACCIRDING TO THIS APPROACH IN FIRST TRAVERSE ITSELF THE ALL PERSON BEFORE 5TH INDEX WILL COMPLETELY BUY THEIR REQUIRED TICKET (I.E ALL WILL THEN NEED 0 TICKET) BUT STILL
WE NEED TO TRAVERSE THEM AGAIN & AGAIN UNTILL tickets[k] BECOMES 0.......WHICH INCREASES THE T.C 

TO AVOID THIS ABOVE APPROACH WILL BE USED

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int size=tickets.size();
        int time=0;
        int i=0;
        while(tickets[k]!=0){
           if(tickets[i]!=0){
            tickets[i]--;
            time++;
           }
           i=(++i)%size;
        }
        return time;
    }
};                                      */