class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=n*2;
        sort(reservedSeats.begin(),reservedSeats.end());
        for(int i=0;i<reservedSeats.size();i++){
            int curr=reservedSeats[i][0];
            int flag1=1;
            int flag2=1;
            int flag3=1;

            while(i<reservedSeats.size()&&reservedSeats[i][0]==curr){
                if(reservedSeats[i][1]>=2&&reservedSeats[i][1]<=5){
                    flag1=0;
                    if(reservedSeats[i][1]>=4&&reservedSeats[i][1]<=5){
                        flag2=0;
                    }
                }else if(reservedSeats[i][1]>=6&&reservedSeats[i][1]<=9){
                    flag3=0;
                    if(reservedSeats[i][1]>=6&&reservedSeats[i][1]<=7){
                        flag2=0;
                    }
                }
                i++;

            }
           if(flag3==0&&flag1==0&&flag2==0){
            ans--;
            ans--;
           }else if(flag3==0||flag2==0||flag1==0){
            ans--;
           }
           i--;
           
        }
        return ans;
    }
};