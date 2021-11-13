#include <iostream>
#include <random>
#include <assert.h>

template<typename T>
class Grid {
private:
    T** memory;
    size_t x_size, y_size;
public:
    Grid(size_t xsize, size_t ysize)
    {
        assert((xsize != 0) && (ysize != 0));
        x_size = xsize;
        y_size = ysize;
        T* x = new T[xsize * ysize];
        T** field = new T * [ysize];
        for (int i = 0; i < ysize; i++)
        {
            field[i] = x + i * xsize;
        }
        memory = field;
    }

    ~Grid()
    {
        for (int i = 0; i < y_size; i++)
            delete[] memory[i];
        delete[] memory;
        x_size = y_size = 0;
    }

    T operator()(size_t x_idx, size_t y_idx) const
    {
        assert(x_idx <= x_size && y_idx <= y_size);
        return memory[y_idx][x_idx];
    }

    T& operator()(size_t x_idx, size_t y_idx)
    {
        return memory[y_idx][x_idx];
    }
    size_t get_xsize() const
    {
        return x_size;
    }
    size_t get_ysize() const
    {
        return y_size;
    }
    Grid& operator=(T value)
    {
        for (int i = 0; i < y_size; i++)
            for (int j = 0; j < x_size; j++)
                memory[i][j] = value;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, Grid const& grid)
    {
        for (int i = 0; i < grid.y_size; i++)
        {
            for (int j = 0; j < grid.x_size; j++)
                out << grid.memory[i][j] << ' ';
            out << std::endl;
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Grid& grid)
    {
        for (int i = 0; i < grid.y_size; i++)
            for (int j = 0; j < grid.x_size; j++)
                in >> grid.memory[i][j];
        return in;
    }
};

int main()
{
    int a, b, c;
    std::cout << "1-value test" << std::endl << "Please enter grid size and an integer value" << std::endl;
    std::cin >> a >> b >> c;
    Grid<int> grid1(a, b);
    grid1 = c;
    std::cout << grid1 << std::endl;

    std::cout << "multi values test" << std::endl << "Please enter grid size and char values" << std::endl;
    std::cin >> a >> b;
    Grid<char> grid2(a, b);
    std::cin >> grid2;

    std::cout << grid2 << std::endl;

    std::cout << "float and adressing an element test" << std::endl;
    Grid<float> grid3(2, 2);
    grid3(0, 0) = 1.2;
    grid3(0, 1) = 3.45;
    grid3(1, 0) = 6.786;
    grid3(1, 1) = 10.6374839;

    std::cout << grid3 << std::endl;

}
