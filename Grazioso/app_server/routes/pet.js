var express = require('express');
var router = express.Router();
var controller = require('../Controllers/pet');

<<<<<<< HEAD
<<<<<<< HEAD
/* GET pet page. */
router.get('/:petid', controller.pet); // to display individual pets

module.exports = router;
=======

/* GET home page. */
router.get('/', controller.pet);
 
module.exports = router;
>>>>>>> 2084a8e (app_server update)
=======
/* GET pet page. */
router.get('/:petid', controller.pet); // to display individual pets

module.exports = router;
>>>>>>> 4586d48 (enhancements to app_api and app_server)
