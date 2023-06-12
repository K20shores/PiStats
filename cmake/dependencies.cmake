include(FetchContent)

FetchContent_Declare(amqp-cpp
  GIT_REPOSITORY https://github.com/CopernicaMarketingSoftware/AMQP-CPP.git
  GIT_TAG v4.3.23
)

FetchContent_MakeAvailable(amqp-cpp)
