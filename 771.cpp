//https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int k = 0;
		for (size_t i = 0; i < J.size(); ++i) {
			for (size_t j = 0; j < S.size(); ++j) {
				if (J[i] == S[j]) {
					k += 1;
				}
			}

		}
		return k;
	}
};
