class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        
        // 可以逆向切蛋糕的过程然后使用贪心算法
        // 问题是用什么数据结构来表示一块一块的蛋糕
         sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
         sort(verticalCut.begin(),verticalCut.end(),greater<int>());

        long sum = 0;

        auto i = horizontalCut.begin();
        auto j = verticalCut.begin();

        int p=1,q=1;
         while(i!=horizontalCut.end()||j!=verticalCut.end()){

            if(i == horizontalCut.end()){
                sum+=q*(*j);
                j++;
            }else if(j==verticalCut.end()){
                sum+=p*(*i);
                i++;
            }else if(*i>*j){
                q++;
                sum+=p*(*i);
                i++;
            }else{
                p++;
                sum+=q*(*j);
                j++;
            }

         }


    return sum;
    }
};