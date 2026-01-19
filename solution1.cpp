#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	vector<char> stack;
	for (int i = 0; i < s.size(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			stack.push_back(s[i]);
		}
		else if (i + 1 < s.size())
		{
			if (s[i] == 'z' && s[i+1] == 'e')
			{
				stack.push_back('0');
				i += 3;
			}
			else if (s[i] == 'o' && s[i+1] == 'n')
			{
				stack.push_back('1');
				i += 2;
			}
			else if (s[i] == 't' && s[i+1] == 'w')
			{
				stack.push_back('2');
				i += 2;
			}
			else if (s[i] == 't' && s[i+1] == 'h')
			{
				stack.push_back('3');
				i += 4;
			}
			else if (s[i] == 'f' && s[i+1] == 'o')
			{
				stack.push_back('4');
				i += 3;
			}
			else if (s[i] == 'f' && s[i+1] == 'i')
			{
				stack.push_back('5');
				i += 3;
			}
			else if (s[i] == 's' && s [i + 1] == 'i')
			{
				stack.push_back('6');
				i += 2;
			}
			else if (s[i] == 's'&& s[i+1] == 'e')
			{
				stack.push_back('7');
				i += 4;
			}
			else if (s[i] =='e' && s[i+1] == 'i')
			{
				stack.push_back('8');
				i += 4;
			}
			else if (s[i] == 'n' && s[i+1] == 'i')
			{
				stack.push_back('9');
				i += 3;
			}
		}
	}
	for (int i = 0; i < stack.size(); i++)
	{
		answer = answer * 10 + (stack[i] - '0');
	}
	return answer;
}


#include <regex>
int solution(string s) {
	s = regex_replace(s, regex("zero"), "0");
	s = regex_replace(s, regex("one"), "1");
	s = regex_replace(s, regex("two"), "2");
	s = regex_replace(s, regex("three"), "3");
	s = regex_replace(s, regex("four"), "4");
	s = regex_replace(s, regex("five"), "5");
	s = regex_replace(s, regex("six"), "6");
	s = regex_replace(s, regex("seven"), "7");
	s = regex_replace(s, regex("eight"), "8");
	s = regex_replace(s, regex("nine"), "9");
	return stoi(s);
}
int solution(string s) {
	int answer = 0;

	string num_str[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			answer = answer * 10 + s[i] - '0';
		}
		else {
			for (int j = 0; j < 10; j++) {
				if (!num_str[j].compare(0, num_str[j].length(), s, i, num_str[j].length())) {
					answer = answer * 10 + j;
				}
			}

		}
	}

	return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

vector<string> numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

int solution(string s) {
	int answer = 0;
	regex r;
	for (int i = 0; i < numbers.size(); i++) {
		r = numbers[i];
		s = regex_replace(s, r, to_string(i));
	}
	answer = stoi(s);
	return answer;
}
#include <string>
#include <unordered_map>

using namespace std;

int solution(string s) {
	unordered_map<string, char> table = {
		{"zero", '0'}, {"one", '1'}, {"two", '2'},
		{"three", '3'}, {"four", '4'}, {"five", '5'},
		{"six", '6'}, {"seven", '7'}, {"eight", '8'},
		{"nine", '9'}
	};

	string result;

	for (int i = 0; i < s.size(); ) {
		if (isdigit(s[i])) {
			result += s[i];
			i++;
		}
		//else {
		//	for (auto& [word, digit] : table) {
		//		if (s.substr(i, word.size()) == word) {
		//			result += digit;
		//			i += word.size();
		//			break;
		//		}
		//	}
		//}
		for (auto& pair : table)
		{
			const string& word = pair.first;
			char digit = pair.second;

			if (s.substr(i, word.size()) == word) {
				result += digit;
				i += word.size();
				break;
			}
		}
	}
	return stoi(result);
}
