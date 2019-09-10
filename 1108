//https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
        string temp;
		for (size_t i = 0; i < address.size(); ++i) {
			if (address[i] == '.') {
				temp += "[.]";
			}
			else {
				temp += address[i];
			}
		}
		return temp;
    }
};
