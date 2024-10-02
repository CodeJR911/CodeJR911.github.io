/* GET Homepage */
const index = (req, res) => {
    res.render('index', { title: 'Pet Rescue' });
};

module.exports = { index;
}