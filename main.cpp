#include <fstream>
#include <iostream>
#include <sstream>

#include "./include/nlohmann/json.hpp"
#include "./src/JCAAnalyser.hpp"
#include "./src/Constants.hpp"
#include "./include/Utils.hpp"

using namespace SOL2CPN;
using namespace std;

int main(int argc, char** argv){
	string ast_json_file_name = "./test/jca_test/EtherLotto.sol_json.ast";
	string output_file_name = "./output/EtherLotto.lna";

	ifstream ast_json_file_stream(ast_json_file_name);

	string new_line;
	string ast_json_content;

	while (getline(ast_json_file_stream, new_line)) {
		ast_json_content = ast_json_content + new_line + "\n";
	}

	if (ast_json_content != "") {
		
		nlohmann::json ast_json = nlohmann::json::parse(ast_json_content);

		std::cout << "start analyse ast-json-compact file !!!\n";
		JCAAnalyser jca_analyser(ast_json);
		RootNodePtr root_node = jca_analyser.analyse();
		std::cout << "end analyse ast-json-compact file !!!\n";
    }
    
    ast_json_file_stream.close();

    exit(ErrorCode::SUCCESS);

    return 0;
}
