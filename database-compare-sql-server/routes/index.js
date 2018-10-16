const express = require('express');
const router = express.Router();
const IndexController = require('../app/controllers/IndexController');
const controller = new IndexController();

/* GET home page. */
router.get('/', controller.indexAction);
router.get('/tables', controller.tablesAction);
router.get('/columns', controller.columnsAction);
router.get('/report', controller.reportAction);

module.exports = router;
