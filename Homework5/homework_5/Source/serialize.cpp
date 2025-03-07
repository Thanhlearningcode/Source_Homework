#include "serialize.hpp"

	namespace ipb::serialization {
		void Serialize(const cv::Mat& m, const std::string& filename) {
			std::ofstream ofs(filename, std::ios::binary);
		/* Check file is opend */
	        if (!ofs.is.open()) {
		    std::cerr<<"File is not opened : " << filename<< std::endl;
		    return -1;
		}
		
		/* Save ma tran so hang va cot */
	   	   int rows = m.rows;
		   int cols = m.cols;
		   int type = m.type(); //< Chon loai du lieu 
		/* Ghi kich thuoc va loai cua ma tran */

		   ofs.write (reinterpret_cast<char*>(&row),   sizeof(rows));
		   ofs.write (reinterpret_cast<char*>(&cols),  sizeof(cols));
		   ofs.write (reinterpret_cast<char*>*(&type), sizeof(type)); 
		}
	
	}
