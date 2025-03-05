#include "image_browser.hpp"
#include "html_writer.hpp"
#include <iostream>

namespace image_browser {
	void AddFullRow (const ImageRow& row, bool first_row) {
	   html_writer::OpenRow();
	   for (size_t i=0; i<row.size(); ++i){
	   	const auto& [img_path,score] = row[i]; //< Giai nen tuple
		bool highligh = (first_row && i==0); //< Anh dau tien 
		html_writer::AddImage (img_path,score,highligh);
	   }
	 html_writer::CloseRow();
}
	void CreateImageBrowser(const std::string& title, const std::string& stylesheet, const std::vector<ImageRow>& rows) {
	        std::cout << "<html>\n<head>\n";
                html_writer::AddTitle(title);
                html_writer::AddCSSStyle(stylesheet);
                std::cout << "</head>\n";
    
                html_writer::OpenBody();
    
                for (size_t i = 0; i < rows.size(); ++i) {
                  AddFullRow(rows[i], i == 0);  //< hang dau tien
    }

    html_writer::CloseBody();
    std::cout << "</html>\n";
}
	}
