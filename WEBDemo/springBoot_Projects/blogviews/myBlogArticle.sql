/*
Navicat MySQL Data Transfer

Source Server         : root
Source Server Version : 50131
Source Host           : 49.234.52.235:3306
Source Database       : myblog

Target Server Type    : MYSQL
Target Server Version : 50131
File Encoding         : 65001

Date: 2021.10.31
*/

CREATE Database myblog;
use myblog;
set names utf8£»

-- ----------------------------
--  Table structure for `article`
-- ----------------------------
DROP TABLE IF EXISTS `article`;
CREATE TABLE `me_article` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `comment_amount` int(8) DEFAULT NULL,
  `read_amount` int(11) DEFAULT NULL,  
  `like_amount` int(11) DEFAULT NULL,
  `create_date` datetime DEFAULT NULL,
  `summary` varchar(100) DEFAULT NULL,
  `title` varchar(64) DEFAULT NULL,
  `view_path` varchar(40) DEFAULT NULL,
  `author` varchar(20) DEFAULT NULL,
  `content` text DEFAULT NULL,
  `category` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`id`)
);

-- ----------------------------
--  Table structure for `article_comment`
-- ----------------------------
DROP TABLE IF EXISTS `article_comment`;
CREATE TABLE `article_comment` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `comment_content` varchar(100) DEFAULT NULL,
    `article_id` int(11) DEFAULT NULL,
    `date` date DEFAULT NULL,
     PRIMARY KEY (`id`)
);

-- ----------------------------
--  Table structure for `article_comment`
-- ----------------------------
DROP TABLE IF EXISTS `me`;
CREATE TABLE `me` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(20) DEFAULT NULL,
    `gender` int(1) DEFAULT NULL,
    `me_summary` varchar(50) DEFAULT NULL,
    `qq_number` varchar(20) DEFAULT NULL,
    `wechar_number` varchar(20) DEFAULT NULL,
    `github_number` varchar(30) DEFAULT NULL,
    `me_detials` text DEFAULT NULL;
     PRIMARY KEY (`id`)
);



