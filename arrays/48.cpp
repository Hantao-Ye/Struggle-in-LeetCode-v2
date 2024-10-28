#include <vector>

void rotate(std::vector<std::vector<int>> &matrix)
{
    int size = matrix.size();

    for (int iter{}, batch_size = size - 1; batch_size > 0; iter++, batch_size -= 2)
    {
        std::vector<int> prev(batch_size, 0);
        for (int column_idx = 0; column_idx < batch_size; column_idx++)
        {
            prev[column_idx] = matrix[iter][column_idx + iter];
        }

        for (int row_idx = 0; row_idx < batch_size; row_idx++)
        {
            int temp = prev[row_idx];
            prev[row_idx] = matrix[row_idx + iter][size - 1 - iter];
            matrix[row_idx + iter][size - 1 - iter] = temp;
        }

        for (int column_idx = 0; column_idx < batch_size; column_idx++)
        {
            int temp = prev[column_idx];
            prev[column_idx] = matrix[size - 1 - iter][size - 1 - iter - column_idx];
            matrix[size - 1 - iter][size - 1 - iter - column_idx] = temp;
        }

        for (int row_idx = 0; row_idx < batch_size; row_idx++)
        {
            int temp = prev[row_idx];
            prev[row_idx] = matrix[size - 1 - iter - row_idx][iter];
            matrix[size - 1 - iter - row_idx][iter] = temp;
        }

        for (int column_idx = 0; column_idx < batch_size; column_idx++)
        {
            matrix[iter][column_idx + iter] = prev[column_idx];
        }
    }
}