FROM reo7sp/tgbot-cpp
MAINTAINER Oleg Morozenkov <a@reo7sp.ru>

WORKDIR /usr/src/cppbot
COPY . .
RUN cmake .
RUN make -j4
CMD ./cppbot
