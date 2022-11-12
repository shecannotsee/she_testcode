//
// Created by  shecannotsee on 2022/11/4.
//

#ifndef SQLITE3_TEST_HEADER_H
#define SQLITE3_TEST_HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

namespace method1 {
void main() {
  /* base test */ {
    std::cout<<"base test:\n";
    std::string str1 = "{ \"happy\": true, \"pi\": 3.141 }";
    std::string str2 = R"({"happy": true, "pi": 3.141})";
    std::cout<<"std::string :"<<str1<<std::endl;
    // 从字符串转化成json
    nlohmann::json json = nlohmann::json::parse(str1);
    std::cout<<"nlohmann json :"<<json<<std::endl;
    // 将nlohmann json 转换为std::string
    std::string str3 = json.dump(4);
    std::cout<<"nlohmann json to std::string :"<<str3<<std::endl;
  };
  /* get json key value */ {
    std::cout<<"\nget json key value test:\n";
    std::string str1 = "{ \"happy\": true, \"pi\": 3.141 }";
    nlohmann::json json = nlohmann::json::parse(str1);
    std::cout<<"json[\"happy\"] :"<<json["happy"]<<std::endl;
    std::cout<<"json[\"pi\"] :"<<json["pi"]<<std::endl;
    std::cout<<"json[\"unknown\"]:"<<json["unknown"]<<std::endl;
    std::cout<<"json.at(\"unknown\"):"<<json.at("unknown")<<std::endl;
    if(json["unknown"].empty())
      std::cout<<"no json key is unknown.\n";
    else
      std::cout<<"has json-key is unknown\n";
  };
  /* push array */ {
    std::cout<<"\npush array test:\n";
    nlohmann::json data1 = nlohmann::json::parse("{ \"happy\": true, \"pi\": 3.141 }");
    nlohmann::json json;
    json["data"].push_back(data1);
    data1["pi"] = 2.2222;
    json["data"].push_back(data1);
    std::cout<<"after push array :"<<json.dump(4)<<std::endl;
    std::cout<<"json data[] size :"<<json["data"].size()<<std::endl;
    for (auto& e:json["data"]) {
      std::cout<<e["happy"]<<","<<e["pi"]<<std::endl;
    }
  };
  /* get data from json array */ {
    std::cout<<"\nget data from json array\n";
    std::string str1 = "{ \"open\": [1,2,3,4] }";
    nlohmann::json json = nlohmann::json::parse(str1);
    std::cout<<"json"<<json["open"].dump()<<std::endl;
    for (auto& e:json["open"]){
      std::cout<<e<<std::endl;
    };
    nlohmann::json json2 = nlohmann::json::parse(json["open"].dump());
    std::cout<<"json2 dump :"<<json2.dump()<<std::endl;
    for (auto& e:json2) {
      if (typeid(std::string)==typeid(e.dump()))
        std::cout<<"e means std::string";
      else
        std::cout<<"e not std::string";
      std::cout<<e<<std::endl;
    }
  };

};
};// namespace method1

namespace method2 {
void main() {
  /* get json from json.file */ {
    std::cout<<"\nget json from json.file test:\n";
    std::ifstream json_file("../user_request.json");// 注意读取文件的位置
    nlohmann::json json_request;
    json_file>>json_request;
    std::cout<<json_request.dump(4)<<std::endl;
    std::map<std::string, std::string> hash;
    for (auto& e:json_request["rules"] ) {
      std::cout<<e["id"].dump()<<"."<<e["name"].dump()<<std::endl;
      if (e["id"]=="1") {
        std::cout<<"111111:"<<e["name"]<<std::endl;
      }
      hash.insert(std::make_pair(e["id"].dump(),e["name"].dump()));
    }
    std::cout<<"get rules  id ==1 name:"<<hash["\"1\""]<<std::endl;
    for (auto e:hash) {
      std::cout<<e.first<<":"<<e.second<<std::endl;
    }
    nlohmann::json user;
    user["name"] = "Carry";
    user["age"]  = 25;
  };
};

};// namespace method2

namespace method3 {
void main() {
  nlohmann::json data1 = nlohmann::json::parse("{ \"happy\": true, \"pi\": 3 }");
  std::string a = data1["pi"].dump();
  std::cout<<"method3 :["<<a<<"]"<<std::endl;
};
};// namespace method3

#endif //SQLITE3_TEST_HEADER_H
