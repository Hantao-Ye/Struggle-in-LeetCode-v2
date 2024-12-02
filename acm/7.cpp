#include <iostream>
#include <sstream>

class Solution
{
public:
    std::pair<float, bool> gpa(std::string grades)
    {
        int course_count = 0;
        int course_credit_count = 0;

        std::istringstream iss(grades);
        char grade(0);

        while (iss >> grade)
        {
            if ((grade >= 'A' && grade <= 'D') || (grade == 'F'))
            {
                course_count += 1;
                if (grade != 'F')
                {
                    course_credit_count += ('E' - grade);
                }
            }
            else
            {
                return {0, false};
            }
        }

        return {course_credit_count / (float)course_count, true};
    }
};

int main()
{
    Solution s{};
    while (true)
    {
        std::string grades{};
        std::getline(std::cin, grades);

        if (grades.size() > 0)
        {
            auto output = s.gpa(grades);

            if (output.second)
            {
                std::printf("%.2f\n", output.first);
            }
            else
            {
                std::cout << "Unknown" << std::endl;
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}