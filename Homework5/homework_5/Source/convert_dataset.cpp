#include "convert_dataset.hpp"

	namespace ipb::serialization::sifts {
	
		void ConvertDataset(const std::filesystem::path& img_path) {
			
			if (!std::filesystem::exists(img_path) || !std::filesystem::is_directory(img_path)) {
				std::cerr<<"Loi mo file " <<std::endl;
				return -1;
			}
		}
		
	}
