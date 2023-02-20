
#ifndef LAB_WEEK_8_EXERCISE3_HPP
#define LAB_WEEK_8_EXERCISE3_HPP

#include <algorithm>
#include <chrono>
#include <deque>
#include <iostream>
#include <optional>
#include <string>
#include <thread>
#include <memory>

// TODO: The code located in this file might use more memory than intended. Basically, there is a bug hidden here.
//  A solution will only need to change the logic in a single function.

namespace ais1002 {

    // A FIFO cache designed to hold at most `maxSize` number of entries.
    // https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)
    class Cache {

    public:
        explicit Cache(unsigned int maxSize) : maxSize_(maxSize) {}

        [[nodiscard]] size_t size() const {
            return queue_.size();
        }

        [[nodiscard]] unsigned int getNumCacheHits() const {
            return cacheHits_;
        }

        // If the key is located in the cache, return its value, otherwise nullptr
        std::shared_ptr<std::string> get(const std::string &key) {
            // check if the cache contains the key.
            auto find = std::find_if(queue_.begin(), queue_.end(), [&](auto &pair) {
                return pair.first == key;
            }); // find holds an iterator to either the found element (match) or the end of the queue (no match)
            if (find != std::end(queue_)) { // do we have a match
                cacheHits_++;// we got a hit
                return find->second; // same as (*find).second
            } else {
                return nullptr; // no hit. If the result type where stack allocated, we could have used std::optional to represent no value
            }
        }

        // put a new entry in the cache
        void put(const std::string &url, const std::shared_ptr<std::string> &content) {
            queue_.emplace_back(url, content);
            if (queue_.size() > maxSize_) {
                queue_.pop_front();
            }
        }

    private:
        unsigned int maxSize_;// <--- hint: unused variable. Did someone forget something?
        unsigned int cacheHits_ = 0;

        // https://en.cppreference.com/w/cpp/container/deque
        std::deque<std::pair<std::string, std::shared_ptr<std::string>>> queue_;
    };

    // Class that **simulates** a URL fetcher.
    // That is, an object that downloads the text content of webpages (given by an URL).
    class URLFetcher {

    public:
        explicit URLFetcher(unsigned int maxCacheSize) : cache_(maxCacheSize) {}

        [[nodiscard]] size_t actualCacheSize() const {
            return cache_.size();
        }

        [[nodiscard]] unsigned int numCacheHits() const {
            return cache_.getNumCacheHits();
        }

        // Given a URL, return the text content of that web page (we are just pretending though)
        std::shared_ptr<std::string> getContent(const std::string &url) {
            auto cacheHit = cache_.get(url);
            if (cacheHit) { // same as cacheHit != nullptr
                // Data has previously been "downloaded" and exists in the cache. We just saved some time.
                return cacheHit;
            } else {
                // No hit :( We need to download the content.
                auto content = downloadContent(url);
                // Let's put the data into the cache, so that we might skip "downloading" next time.
                cache_.put(url, std::move(content));
                return content;
            }
        }

    private:
        Cache cache_;

        // returning a stack allocated object would probably work just as fine...
        // the function is static because we are not accessing class members (so we can, but don't have to).
        // Could have been a free function if we wanted to re-use it.
        static std::unique_ptr<std::string> downloadContent(const std::string &url) {

            // Simulate work. The actual time taken by such a function would depend on the internet connection and page content.
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            return std::make_unique<std::string>("Some text that we pretend has been downloaded from a website..");
        }
    };

}// namespace ais1002

#endif//LAB_WEEK_8_EXERCISE3_HPP
