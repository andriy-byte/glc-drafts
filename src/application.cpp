
#include "application.h"


void glc::cli::application_preparation::wrong_preparation() {
    fmt::print("{}", error_preparation_message);
    std::exit(constants::ERROR_EXIT);

}

bool glc::cli::application_preparation::is_correct_arguments_quantity(const int &argc) {
    if (argc != constants::ARGUMENTS_QUANTITY) {
        error_preparation_message = fmt::format("{}{}", "Error, wrong aruments quantity, required ",
                                                constants::ARGUMENTS_QUANTITY);
        return false;
    }
    return true;
}

bool glc::cli::application_preparation::is_correct_arguments(const int &argc, const char **argv) {
    try {
        load_commands(description);
        po::store(po::parse_command_line(argc, argv, description), arguments_map);
    } catch (po::error &program_option_error) {
        error_preparation_message = std::string("Error : ") + program_option_error.what();
        return false;
    }
    return true;

}

glc::cli::po::variables_map &glc::cli::application_preparation::get_arguments_map() const {
    return arguments_map;
}

glc::cli::po::options_description &glc::cli::application_preparation::get_description() const {
    return description;
}

void glc::cli::application::run() {
    project::mode mode(description);
    auto oparations = create_operations();
    for (const auto &it: arguments_map) {
        oparations[it.first](mode);
    }


}

glc::cli::application::application(boost::program_options::variables_map &arguments_map,
                                   boost::program_options::options_description &description):
                                   arguments_map(std::move(arguments_map)),
                                   description(std::move(description)){

}





