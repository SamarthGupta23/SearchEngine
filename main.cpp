#include <iostream>
#include <string>
#include "crawler.hpp"

int main() {
    parser parser;

    std::string html = R"(<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
    <meta charset="UTF-8">
    <title>Sample Article - Wikipedia</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <!-- MediaWiki-style metadata -->
    <meta name="generator" content="MediaWiki 1.42.0">
    <meta name="description" content="Mock Wikipedia page with scripts">

    <!-- Styles -->
    <style>
        body {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI",
                         Roboto, Oxygen, Ubuntu, Cantarell, "Helvetica Neue", Arial, sans-serif;
            background-color: #f8f9fa;
            color: #202122;
            margin: 0;
        }

        a { color: #0645ad; text-decoration: none; }
        a:hover { text-decoration: underline; }

        #content {
            max-width: 960px;
            margin: 0 auto;
            background: #fff;
            padding: 1.5rem;
            border-left: 1px solid #a2a9b1;
            border-right: 1px solid #a2a9b1;
        }

        h1.firstHeading {
            font-size: 2em;
            font-weight: normal;
            border-bottom: 1px solid #a2a9b1;
        }

        h2 {
            border-bottom: 1px solid #a2a9b1;
            margin-top: 1.5em;
        }

        .infobox {
            float: right;
            width: 260px;
            border: 1px solid #a2a9b1;
            background: #f8f9fa;
            font-size: 90%;
            margin-left: 1em;
        }

        .infobox th {
            background: #eaecf0;
            text-align: center;
        }

        .infobox td, .infobox th {
            padding: 0.3em;
        }

        .toc {
            border: 1px solid #a2a9b1;
            background: #f8f9fa;
            padding: 0.5em;
            width: fit-content;
        }

        footer {
            background: #f8f9fa;
            border-top: 1px solid #a2a9b1;
            padding: 1em;
            font-size: 0.85em;
            color: #54595d;
        }

        .mw-clear { clear: both; }
    </style>

    <!-- MediaWiki-style script block -->
    <script>
        /* Global MediaWiki object */
        window.mw = {
            config: {
                values: {
                    wgPageName: "Sample_Article",
                    wgTitle: "Sample Article",
                    wgIsArticle: true,
                    wgNamespaceNumber: 0,
                    wgSiteName: "Wikipedia",
                    wgLanguageCode: "en",
                    wgCurRevisionId: 123456789
                }
            },
            loader: {
                modules: {},
                load: function (name) {
                    this.modules[name] = true;
                }
            },
            log: function (msg) {
                console.log("[mw]", msg);
            }
        };

        mw.log("MediaWiki mock environment initialized");
    </script>
</head>

<body>

<div id="content" class="mw-body" role="main">
    <h1 class="firstHeading">Sample Article</h1>

    <div class="infobox">
        <table>
            <tr><th colspan="2">Sample Article</th></tr>
            <tr>
                <td colspan="2" style="text-align:center;">
                    <img src="" alt="Image placeholder" width="220">
                </td>
            </tr>
            <tr><th>Type</th><td>Demonstration</td></tr>
            <tr><th>Created</th><td>2025</td></tr>
            <tr><th>Purpose</th><td>Wikipedia-style HTML</td></tr>
        </table>
    </div>

    <p>
        <b>Sample Article</b> is a mock page designed to replicate the structure
        and runtime environment of a typical
        <a href="#">Wikipedia</a> article, including embedded scripts and
        MediaWiki-style configuration objects.
    </p>

    <div class="toc">
        <strong>Contents</strong>
        <ul>
            <li><a href="#history">1 History</a></li>
            <li><a href="#structure">2 Structure</a></li>
            <li><a href="#references">3 References</a></li>
        </ul>
    </div>

    <h2 id="history">History</h2>
    <p>
        Wikipedia pages rely heavily on server-generated HTML augmented by
        JavaScript modules. This page statically simulates that environment.
    </p>

    <h2 id="structure">Structure</h2>
    <p>
        The document includes headings, infoboxes, internal links, scripts,
        metadata, and semantic markup consistent with MediaWiki output.
    </p>

    <h2 id="references">References</h2>
    <ol>
        <li>
            Example reference.
            <i>Mock MediaWiki Docs</i>.
            <a href="#">https://example.com</a>
        </li>
    </ol>

    <div class="mw-clear"></div>
</div>

<footer role="contentinfo">
    <p>
        Text is available under the
        <a href="#">Creative Commons Attribution-ShareAlike License</a>.
    </p>
</footer>

</body>
</html>
)";

    parser.parse(html);
    std::cout << parser.getText() << std::endl;

    return 0;
}
