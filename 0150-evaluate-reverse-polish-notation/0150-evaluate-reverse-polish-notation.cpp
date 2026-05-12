class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();

        stack<int>st;

        int i = 0;

        while(i<len){

            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();

                if(tokens[i] == "+"){
                    st.push(top2 + top1);
                }
                else if(tokens[i] == "-"){
                    st.push(top2 - top1);
                }
                else if(tokens[i] == "*"){
                    st.push(top2 * top1);
                }
                else{
                    st.push(top2 / top1);
                }     
            }
            else{
                st.push(stoi(tokens[i]));
            }

            i++; 
        }

        return st.top();
        
    }
};