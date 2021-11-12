//implements objects, surprisingly works (can only store strings)
//oh wait I could have used #include<map>
//sigh
using namespace std;

class object{
public:
	vector<string> keys;
	vector<string> vals;
	string get(string key);
	void set(string key, string val);
};
string object::get(string key){
	for (unsigned int i = 0; i < this->keys.size(); i++){
		if(this->keys[i]==key){
			return this->vals[i];
		}
	}
	return "";
}
void object::set(string key, string val){
	if(this->get(key)==""){
		this->keys.push_back(key);
		this->vals.push_back(val);
	}else{
		for (unsigned int i = 0; i < this->keys.size(); i++){
			if(this->keys[i]==key){
				this->vals[i]=val;
			}
		}
	}
}