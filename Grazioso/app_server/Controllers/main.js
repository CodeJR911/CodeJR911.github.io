/* GET Homepage */
const index = (req, res) => {
    // Example of fetching data (replace with your actual logic)
    const featuredPets = [
      { name: 'Buddy', breed: 'Golden Retriever' },
      { name: 'Lucy', breed: 'Labrador' }
    ];
  
    res.render('index', { 
      title: 'Pet Rescue', 
      featuredPets: featuredPets // Pass data to the view
    });
  };
  
  module.exports = { 
    index 
  };
  