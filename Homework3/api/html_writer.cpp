#include "html_writer.hpp"
#include <filesystem>
#include <iomanip>
#include <iostream>

namespace html_writer {

namespace fs = std::filesystem;

void OpenDocument() {
    std::cout << "<!DOCTYPE html>\n<html>\n";
}

void CloseDocument() {
    std::cout << "</html>\n";
}

void AddCSSStyle(const std::string& stylesheet) {
    std::cout << "<head>\n"
              << "  <link rel='stylesheet' type='text/css' href='" << stylesheet << "'>\n"
              << "</head>\n";
}

void AddTitle(const std::string& title) {
    std::cout << "<title>" << title << "</title>\n";
}

void OpenBody() {
    std::cout << "<body>\n";
}

void CloseBody() {
    std::cout << "</body>\n";
}

void OpenRow() {
    std::cout << "<div class='row'>\n";
}

void CloseRow() {
    std::cout << "</div>\n";
}

void AddImage(const std::string& img_path, float score, bool highlight) {
    fs::path path(img_path);

    /* Check dinh dang anh */
    if (path.extension() != ".png" && path.extension() != ".jpg") {
        std::cerr << "Error: Unsupported file type: " << img_path << std::endl;
        return;
    }

    std::string filename = path.filename().string();  //< Choose namefile, ignore path

    /* Printf HTML if need */
    std::cout << "<div class='image-container' style='margin: 10px; padding: 5px; ";
    if (highlight) {
        std::cout << "border: 3px solid red; ";
    }
    std::cout << "'>\n";

    std::cout << "  <img src='data/" << filename << "' alt='Image' width='300'/>\n"
              << "  <p>Score: " << std::fixed << std::setprecision(2) << score << "</p>\n"
              << "</div>\n";
}

	}  

