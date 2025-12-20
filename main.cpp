#include <iostream>
#include <string>
#include "crawler.hpp"

int main() {
    parser parser;

    std::string html = R"(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>My First Website</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }

        header {
            background-color: #222;
            color: white;
            padding: 20px;
            text-align: center;
        }

        nav {
            background-color: #444;
            padding: 10px;
            text-align: center;
        }

        nav a {
            color: white;
            margin: 0 15px;
            text-decoration: none;
            font-weight: bold;
        }

        nav a:hover {
            text-decoration: underline;
        }

        main {
            padding: 20px;
        }

        footer {
            background-color: #222;
            color: white;
            text-align: center;
            padding: 10px;
            position: fixed;
            bottom: 0;
            width: 100%;
        }
    </style>
</head>
<body>

<header>
    <h1>Welcome to My Website</h1>
    <p>A simple HTML starter page</p>
</header>

<nav>
    <a href="#">Home</a>
    <a href="#">About</a>
    <a href="#">Projects</a>
    <a href="#">Contact</a>
</nav>

<main>
    <h2>About</h2>
    <p>
        This is a basic website built using only HTML and CSS.
        You can use this as a starting point for learning web development.
    </p>

    <h2>Features</h2>
    <ul>
        <li>Simple layout</li>
        <li>Responsive design</li>
        <li>Clean structure</li>
    </ul>
</main>

<footer>
    <p>&copy; 2025 My Website</p>
</footer>

</body>
</html>)";

    parser.parse(html);
    std::cout << parser.getText() << std::endl;

    return 0;
}
