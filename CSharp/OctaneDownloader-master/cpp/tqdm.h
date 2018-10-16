#ifndef TQDM_H
#define TQDM_H
#include <io.h>
#include <chrono>
#include <ctime>
#include <numeric>
#include <ios>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class tqdm {
    private:
        // time, iteration counters and deques for rate calculations
        std::chrono::time_point<std::chrono::system_clock> t_first = std::chrono::system_clock::now();
        std::chrono::time_point<std::chrono::system_clock> t_old = std::chrono::system_clock::now();
        int n_old = 0;
        std::vector<double> deq_t;
        std::vector<int> deq_n;
        int nupdates = 0;
        int total_ = 0;
        int period = 1;
        unsigned int smoothing = 50;
        bool use_ema = true;
        float alpha_ema = 0.1;

        std::vector<const char*> bars = {" ", "▏", "▎", "▍", "▋", "▋", "▊", "▉", "▉"};
        bool in_screen = (system("test $STY >nul 2>&1") == 0);
        bool in_tmux = (system("test $TMUX >nul 2>&1") == 0);
        bool is_tty = _isatty(1);
        bool use_colors = true;
        bool color_transition = true;
        int width = 40;

        std::string right_pad = "▏";
        std::string label = "";

        void hsv_to_rgb(float h, float s, float v, int& r, int& g, int& b) {
            if (s < 1e-6) {
                v *= 255.;
                r = v; g = v; b = v;
            }
            int i = (int)(h*6.0);
            float f = (h*6.)-i;
            int p = (int)(255.0*(v*(1.-s)));
            int q = (int)(255.0*(v*(1.-s*f)));
            int t = (int)(255.0*(v*(1.-s*(1.-f))));
            v *= 255;
            i %= 6;
            int vi = (int)v;
            if (i == 0)      { r = vi; g = t;  b = p;  }
            else if (i == 1) { r = q;  g = vi; b = p;  }
            else if (i == 2) { r = p;  g = vi; b = t;  }
            else if (i == 3) { r = p;  g = q;  b = vi; }
            else if (i == 4) { r = t;  g = p;  b = vi; }
            else if (i == 5) { r = vi; g = p;  b = q;  }
        }

    public:
        tqdm() {
            if (in_screen) {
                set_theme_basic();
                color_transition = false;
            } else if (in_tmux) {
                color_transition = false;
            }
        }

        void reset() {
            t_first = std::chrono::system_clock::now();
            t_old = std::chrono::system_clock::now();
            n_old = 0;
            deq_t.clear();
            deq_n.clear();
            period = 1;
            nupdates = 0;
            total_ = 0;
            label = "";
        }

        void set_theme_line() { bars = {"─", "─", "─", "╾", "╾", "╾", "╾", "━", "═"}; }
        void set_theme_circle() { bars = {" ", "◓", "◑", "◒", "◐", "◓", "◑", "◒", "#"}; }
        void set_theme_braille() { bars = {" ", "⡀", "⡄", "⡆", "⡇", "⡏", "⡟", "⡿", "⣿" }; }
        void set_theme_braille_spin() { bars = {" ", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠇", "⠿" }; }
        void set_theme_basic() {
            bars = {" ", " ", " ", " ", " ", " ", " ", " ", "#"}; 
            right_pad = "|";
        }
        void set_label(std::string label_) { label = label_; }
        void disable_colors() {
            color_transition = false;
            use_colors = false;
        }

        void finish() {
            progress(total_,total_);
            printf("\n");
            fflush(stdout);
        }
        void progress( int curr, int tot) {
            if(is_tty && (curr%period == 0)) {
                total_ = tot;
                nupdates++;
                auto now = std::chrono::system_clock::now();
                double dt = ((std::chrono::duration<double>)(now - t_old)).count();
                double dt_tot = ((std::chrono::duration<double>)(now - t_first)).count();
                int dn = curr - n_old;
                n_old = curr;
                t_old = now;
                if (deq_n.size() >= smoothing) deq_n.erase(deq_n.begin());
                if (deq_t.size() >= smoothing) deq_t.erase(deq_t.begin());
                deq_t.push_back(dt);
                deq_n.push_back(dn);

                double avgrate = 0.;
                if (use_ema) {
                    avgrate = deq_n[0] / deq_t[0];
                    for (unsigned int i = 1; i < deq_t.size(); i++) {
                        double r = 1.0*deq_n[i]/deq_t[i];
                        avgrate = alpha_ema*r + (1.0-alpha_ema)*avgrate;
                    }
                } else {
                    double dtsum = std::accumulate(deq_t.begin(),deq_t.end(),0.);
                    int dnsum = std::accumulate(deq_n.begin(),deq_n.end(),0.);
                    avgrate = dnsum/dtsum;
                }

                // learn an appropriate period length to avoid spamming stdout
                // and slowing down the loop, shoot for ~25Hz and smooth over 3 seconds
                if (nupdates > 10) {
                    period = (int)( std::min(std::max((1.0/25)*curr/dt_tot,1.0), 5e5));
                    smoothing = 25*3;
                }
                double peta = (tot-curr)/avgrate;
                double pct = (double)curr/(tot*0.01);
                if( ( tot - curr ) <= period ) {
                    pct = 100.0;
                    avgrate = tot/dt_tot;
                    curr = tot;
                    peta = 0;
                }

                double fills = ((double)curr / tot * width);
                int ifills = (int)fills;

                printf("\015 ");
                if (use_colors) {
                    if (color_transition) {
                        // red (hue=0) to green (hue=1/3)
                        int r = 255, g = 255, b = 255;
                        hsv_to_rgb(0.0+0.01*pct/3,0.65,1.0, r,g,b);
                        printf("\033[38;2;%d;%d;%dm ", r, g, b);
                    } else {
                        printf("\033[32m ");
                    }
                }
                for (int i = 0; i < ifills; i++) std::cout << bars[8];
                if (!in_screen and (curr != tot)) printf("%s",bars[(int)(8.0*(fills-ifills))]);
                for (int i = 0; i < width-ifills-1; i++) std::cout << bars[0];
                printf("%s ", right_pad.c_str());
                if (use_colors) printf("\033[1m\033[31m");
                printf("%4.1f%% ", pct);
                if (use_colors) printf("\033[34m");

                std::string unit = "Hz";
                double div = 1.;
                if (avgrate > 1e6) {
                    unit = "MHz"; div = 1.0e6;
                } else if (avgrate > 1e3) {
                    unit = "kHz"; div = 1.0e3;
                }
                printf("[%4d/%4d | %3.1f %s | %.0fs<%.0fs] ", curr,tot,  avgrate/div, unit.c_str(), dt_tot, peta);
                printf("%s ", label.c_str());
                if (use_colors) printf("\033[0m\033[32m\033[0m\015 ");

                if( ( tot - curr ) > period ) fflush(stdout);

            }
        }
};
#endif
