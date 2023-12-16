#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <iomanip>

class MobileData {
public:
    MobileData(int battery_power, int blue, double clock_speed, int dual_sim, int fc, int four_g,
               int int_memory, double m_dep, int mobile_wt, int n_cores, int pc, int px_height,
               int px_width, int ram, int sc_h, int sc_w, int talk_time, int three_g,
               int touch_screen, int wifi, int price_range)
        : battery_power(battery_power), blue(blue), clock_speed(clock_speed), dual_sim(dual_sim),
          fc(fc), four_g(four_g), int_memory(int_memory), m_dep(m_dep), mobile_wt(mobile_wt),
          n_cores(n_cores), pc(pc), px_height(px_height), px_width(px_width), ram(ram),
          sc_h(sc_h), sc_w(sc_w), talk_time(talk_time), three_g(three_g),
          touch_screen(touch_screen), wifi(wifi), price_range(price_range) {}

    int getBatteryPower() const { return battery_power; }
    int getBlue() const { return blue; }
    double getClockSpeed() const { return clock_speed; }
    int getDualSim() const { return dual_sim; }
    int getFc() const { return fc; }
    int getFourG() const { return four_g; }
    int getIntMemory() const { return int_memory; }
    double getMDep() const { return m_dep; }
    int getMobileWt() const { return mobile_wt; }
    int getNCores() const { return n_cores; }
    int getPc() const { return pc; }
    int getPxHeight() const { return px_height; }
    int getPxWidth() const { return px_width; }
    int getRam() const { return ram; }
    int getScH() const { return sc_h; }
    int getScW() const { return sc_w; }
    int getTalkTime() const { return talk_time; }
    int getThreeG() const { return three_g; }
    int getTouchScreen() const { return touch_screen; }
    int getWifi() const { return wifi; }
    int getPriceRange() const { return price_range; }

private:
    int battery_power;
    int blue;
    double clock_speed;
    int dual_sim;
    int fc;
    int four_g;
    int int_memory;
    double m_dep;
    int mobile_wt;
    int n_cores;
    int pc;
    int px_height;
    int px_width;
    int ram;
    int sc_h;
    int sc_w;
    int talk_time;
    int three_g;
    int touch_screen;
    int wifi;
    int price_range;
};

class MobileDataReader {
public:
    MobileDataReader(const std::string& filename) : filename(filename) {}

    std::vector<MobileData> readData() {
        std::ifstream csvFile{filename};
        std::vector<MobileData> data;
        std::string line;

        if (csvFile.is_open()) {
            // Read and discard the header line
            std::getline(csvFile, line);

            while (std::getline(csvFile, line)) {
                try {
                    std::vector<std::string> tokens = tokenize(line, ',');
                    if (tokens.size() != 21) {
                        std::cerr << "Bad line: " << line << std::endl;
                        continue;
                    }

                    // Convert tokens to appropriate types
                    int battery_power = std::stoi(tokens[0]);
                    int blue = std::stoi(tokens[1]);
                    double clock_speed = std::stod(tokens[2]);
                    int dual_sim = std::stoi(tokens[3]);
                    int fc = std::stoi(tokens[4]);
                    int four_g = std::stoi(tokens[5]);
                    int int_memory = std::stoi(tokens[6]);
                    double m_dep = std::stod(tokens[7]);
                    int mobile_wt = std::stoi(tokens[8]);
                    int n_cores = std::stoi(tokens[9]);
                    int pc = std::stoi(tokens[10]);
                    int px_height = std::stoi(tokens[11]);
                    int px_width = std::stoi(tokens[12]);
                    int ram = std::stoi(tokens[13]);
                    int sc_h = std::stoi(tokens[14]);
                    int sc_w = std::stoi(tokens[15]);
                    int talk_time = std::stoi(tokens[16]);
                    int three_g = std::stoi(tokens[17]);
                    int touch_screen = std::stoi(tokens[18]);
                    int wifi = std::stoi(tokens[19]);
                    int price_range = std::stoi(tokens[20]);

                    // Create MobileData object and store in vector
                    data.emplace_back(battery_power, blue, clock_speed, dual_sim, fc, four_g,
                                      int_memory, m_dep, mobile_wt, n_cores, pc, px_height,
                                      px_width, ram, sc_h, sc_w, talk_time, three_g,
                                      touch_screen, wifi, price_range);
                } catch (const std::exception& e) {
                    std::cerr << "Exception caught: " << e.what() << std::endl;
                    std::cerr << "Bad line: " << line << std::endl;
                }
            }
            csvFile.close();
        } else {
            throw std::runtime_error("Failed to open the file");
        }

        return data;
    }

    void printSummary(const std::vector<MobileData>& data) {
        // Print header
        std::cout << std::setw(15) << "Battery Power" << std::setw(5) << "Blue"
                  << std::setw(15) << "Clock Speed" << std::setw(10) << "Dual SIM"
                  << std::setw(5) << "FC" << std::setw(5) << "4G" << std::setw(15) << "Internal Memory"
                  << std::setw(10) << "M_Dep" << std::setw(10) << "Mobile Weight"
                  << std::setw(10) << "N Cores" << std::setw(5) << "PC" << std::setw(10) << "Px Height"
                  << std::setw(10) << "Px Width" << std::setw(10) << "RAM" << std::setw(5) << "SC H"
                  << std::setw(5) << "SC W" << std::setw(10) << "Talk Time" << std::setw(5) << "3G"
                  << std::setw(15) << "Touch Screen" << std::setw(5) << "WiFi" << std::setw(15) << "Price Range"
                  << std::endl;

        // Print data
        for (const auto& mobile : data) {
            std::cout << std::setw(15) << mobile.getBatteryPower() << std::setw(5) << mobile.getBlue()
                      << std::setw(15) << mobile.getClockSpeed() << std::setw(10) << mobile.getDualSim()
                      << std::setw(5) << mobile.getFc() << std::setw(5) << mobile.getFourG()
                      << std::setw(15) << mobile.getIntMemory() << std::setw(10) << mobile.getMDep()
                      << std::setw(10) << mobile.getMobileWt() << std::setw(10) << mobile.getNCores()
                      << std::setw(5) << mobile.getPc() << std::setw(10) << mobile.getPxHeight()
                      << std::setw(10) << mobile.getPxWidth() << std::setw(10) << mobile.getRam()
                      << std::setw(5) << mobile.getScH() << std::setw(5) << mobile.getScW()
                      << std::setw(10) << mobile.getTalkTime() << std::setw(5) << mobile.getThreeG()
                      << std::setw(15) << mobile.getTouchScreen() << std::setw(5) << mobile.getWifi()
                      << std::setw(15) << mobile.getPriceRange() << std::endl;
        }
    }

private:
    std::vector<std::string> tokenize(const std::string& csvLine, char separator) {
        std::vector<std::string> tokens;
        std::istringstream tokenStream(csvLine);
        std::string token;

        while (std::getline(tokenStream, token, separator)) {
            tokens.push_back(token);
        }

        return tokens;
    }

    std::string filename;
};

int main() {
    try {
        MobileDataReader reader("train.csv");
        std::vector<MobileData> data = reader.readData();
        reader.printSummary(data);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
