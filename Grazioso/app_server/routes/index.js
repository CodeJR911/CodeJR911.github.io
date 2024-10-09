var express = require('express');
var router = express.Router();
<<<<<<< HEAD
<<<<<<< HEAD
var controller = require('../Controllers/main'); // Import the main controller

/* GET home page. */
router.get('/', controller.index); // Use the index function from the controller
=======

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});
>>>>>>> 2084a8e (app_server update)
=======
var controller = require('../Controllers/main'); // Import the main controller

/* GET home page. */
router.get('/', controller.index); // Use the index function from the controller
>>>>>>> 4586d48 (enhancements to app_api and app_server)

module.exports = router;
