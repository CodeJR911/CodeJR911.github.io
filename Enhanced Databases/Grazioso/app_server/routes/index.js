var express = require('express');
var router = express.Router();
var controller = require('../Controllers/main'); // Import the main controller

/* GET home page. */
router.get('/', controller.index); // Use the index function from the controller

module.exports = router;
