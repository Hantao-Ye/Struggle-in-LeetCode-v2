#include <sstream>
#include <iostream>

class Solution
{
public:
    int isPrefixOfWord(std::string sentence, std::string searchWord)
    {
        std::string word{};
        std::istringstream iss(sentence);

        int count = 0, index = -1;

        while (iss >> word)
        {
            count++;

            if (word.size() < searchWord.size())
            {
                continue;
            }
            else
            {
                bool unmatch = false;
                for (size_t i = 0; i < searchWord.size(); i++)
                {
                    if (word[i] != searchWord[i])
                    {
                        unmatch = true;
                        break;
                    }
                }

                if (!unmatch)
                {
                    index = count;
                    break;
                }
            }
        }

        return index;
    }
};

int main()
{
    Solution s{};
    std::string sentence{}, searchWord{};

    while (true)
    {
        std::getline(std::cin, sentence);
        std::getline(std::cin, searchWord);

        if (sentence.size() == 0 || searchWord.size() == 0)
        {
            break;
        }

        std::cout << s.isPrefixOfWord(sentence, searchWord) << std::endl;
    }

    return 0;
}