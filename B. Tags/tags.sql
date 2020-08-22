/*
CREATE TABLE goods(id INTEGER, name TEXT);
CREATE TABLE tags(id INTEGER, name TEXT);
CREATE TABLE tags_goods (tag_id INTEGER, goods_id INTEGER, UNIQUE (tag_id, goods_id));
 
INSERT INTO tags(id, name) VALUES(1, '#tag1');
INSERT INTO tags(id, name) VALUES(2, '#tag2');
INSERT INTO tags(id, name) VALUES(3, '#tag3');
INSERT INTO tags(id, name) VALUES(4, '#tag4');
INSERT INTO tags(id, name) VALUES(5, '#tag5');
 
INSERT INTO goods(id, name) VALUES (1, 'good1');
INSERT INTO goods(id, name) VALUES (2, 'good2');
INSERT INTO goods(id, name) VALUES (3, 'good3');
INSERT INTO goods(id, name) VALUES (4, 'good4');
INSERT INTO goods(id, name) VALUES (5, 'good5');
 
INSERT INTO tags_goods(tag_id, goods_id) VALUES (1, 1);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (2, 1);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (3, 1);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (3, 2);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (4, 2);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (1, 3);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (2, 3);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (3, 3);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (4, 3);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (5, 3);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (2, 4);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (1, 5);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (2, 5);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (3, 5);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (4, 5);
INSERT INTO tags_goods(tag_id, goods_id) VALUES (5, 5);
*/

SELECT goods.id, goods.name
FROM goods
INNER JOIN tags_goods ON tags_goods.goods_id = goods.id
GROUP BY goods.id
HAVING COUNT(1) = (SELECT COUNT(1) FROM TAGS);