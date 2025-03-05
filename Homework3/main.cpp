#include "image_browser.hpp"
#include <vector>
#include <array>
#include <tuple>
#include <string>

int main() {
    using image_browser::ImageRow;
    using ScoredImage = std::tuple<std::string, float>;

    std::vector<ImageRow> rows = {
        ImageRow{ScoredImage{"web_app/data/thanhdeptrai1.png", 0.95f}, 
                 ScoredImage{"web_app/data/thanhdeptrai2.png", 0.89f}, 
                 ScoredImage{"web_app/data/thanhdeptrai3.png", 0.76f}},

        ImageRow{ScoredImage{"web_app/data/thanhdeptrai4.png", 0.85f}, 
                 ScoredImage{"web_app/data/thanhdeptrai5.png", 0.72f}, 
                 ScoredImage{"web_app/data/thanhdeptrai6.png", 0.66f}}
    };

    image_browser::CreateImageBrowser("Chuongtrinh", "style.css", rows);

    return 0;
}


