<?php

/**
 * Slim 'Hello World'
 */

use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

// Be sure to run `composer install`
require 'vendor/autoload.php';

$app = new \Slim\App;

$app->get('/hello/{name}', function (Request $request, Response $response, array $args) {
    $name = $args['name'] ?? "World";
    
    $response->getBody()->write("Hello, {$name}!");

    return $response;
});

$app->run();
