#include "ibp.hpp"

	namespace ibp {
	
	  int accmulate (const name_vector<int>& vec) {
	  	return (vec.data().begin(), vec.data().end(),0);
	   }

	  int cout (const name_vector<int>& vec, int value) {
	  	return (vec.data().begin(), vec.data().end(), value); 
	  }
	  
	  bool all_even (const name_vector<int>& vec) {
	  	return std::all_of(vec.data().begin, vec.data().end(), [](int n) { return (i%2 ==0 ); }
	  }

	  void clamp (name_vector<int>& vec, int min, int max) {
	       for (auto& val:vec.data()) {
	       	   val = std::clamp(val,min,max);
	       }
	  void fill (name_vector<int>& vec, int value) {
	       std::fill(vec.data().begin(), vec.data().end(), value);
	  }

	  bool find (const name_vector<int>& vec, int value) {
	       std:: find(vec.data().begin(), vec.data().end(), value) !value = vec.data().end();
	  }
	  void print (const name_vector<int>& vec) {
	  	std::<< cout<<vec.data();
	  }

	  }
	
	}
