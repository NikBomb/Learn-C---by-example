#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> get_next_row(const std::vector<int> &last_row)
{

    std::vector next_row{1};
    if (last_row.empty())
    {
        return next_row;
    }

    for (size_t idx = 0; idx + 1 <= last_row.size(); ++idx)
    {
        next_row.emplace_back(last_row[idx] + last_row[idx + 1]);
    }
    return next_row;
}

auto generate_triangle(const size_t rows)
{
    std::vector<std::vector<int>> triangle{{1}};
    for (size_t row = 1; row < rows; ++row)
    {
        triangle.push_back(get_next_row(triangle.back()));
    }
    return triangle;
}

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<std::vector<T>> &triangle)
{
    for (const auto &row : triangle)
    {
        std::ranges::copy(row, std::ostream_iterator<T>(s, " "));
        s << '\n';
    }
    return s;
}

int main()
{
    auto triangle = generate_triangle(16);
    std::cout << triangle;
}