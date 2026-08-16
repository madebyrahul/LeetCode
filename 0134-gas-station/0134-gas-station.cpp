class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0,totCost=0;
        for(int val : gas){
            totGas += val;
        }
        for(int val : cost ){
            totCost += val;
        }
        if(totGas < totCost) return -1;
        int netGas = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            netGas += gas[i] - cost[i];
            if(netGas<0){
                start = i+1;
                netGas = 0;
            }
        }
        return start;
    }
};