#include <iostream>
#include <vector>
#include <random>
#include "gnuplot-iostream.h"

int main() {
    Gnuplot gp; // Create a gnuplot object

    int runs = 100000;
    std::vector<std::pair<int, double>> stored_real_odds;

    for (int printed_odds = 1; printed_odds < 100; ++printed_odds) {
        int count = 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 100);
        for (int i = 0; i < runs; ++i) {


            int num1 = dis(gen);
            int num2 = dis(gen);

            double average = static_cast<double>(num1 + num2) / 2.0;

            if (average < printed_odds) {
                count++;
            }
        }
        stored_real_odds.push_back({printed_odds, static_cast<double>(count) / runs * 100.0});
    }

    std::vector<double> x_values, y_values;
    for (const auto& item : stored_real_odds) {
        x_values.push_back(item.first);
        y_values.push_back(item.second);
    }

    gp << "set terminal png\n";
    gp << "set output 'plot_cpp.png'\n";
    gp << "set xlabel 'Displayed Hit Odds'\n";
    gp << "set ylabel 'Actual Hit Odds'\n";
    gp << "set title 'True Hit In FE7 Onwards through at least FE13'\n";
    gp << "set xrange [0:100]\n";
    gp << "set yrange [0:100]\n";
    gp << "set xtics 10\n";
    gp << "set ytics 10\n";
    gp << "set grid\n";
    gp << "plot '-' with linespoints linestyle 1 title 'Data'\n";

    gp.send1d(boost::make_tuple(x_values, y_values));

    return 0;
}
