const axios = require('axios');
const cheerio = require('cheerio');

async function scrapeData() {
  try {
    const { data } = await axios.get('https://rucas.store/');
    const $ = cheerio.load(data);

    const items = [];
    $('.product-grid-item').each((index, element) => {
      const title = $(element).find('.product-title').text().trim();
      const price = $(element).find('.product-price').text().trim();
      const stock = $(element).find('.product-stock-status').text().trim();

      items.push({ title, price, stock });
    });

    console.log(items);
  } catch (error) {
    console.error('Error fetching data:', error);
  }
}

scrapeData();
