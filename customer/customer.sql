-- phpMyAdmin SQL Dump
-- version 4.8.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 30, 2018 at 10:10 AM
-- Server version: 10.1.33-MariaDB
-- PHP Version: 7.2.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `customer`
--

-- --------------------------------------------------------

--
-- Table structure for table `answer`
--

CREATE TABLE `answer` (
  `QuestionNo` int(11) NOT NULL,
  `StoreType` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `CustomerName` varchar(255) NOT NULL,
  `Question` varchar(255) NOT NULL,
  `Answer` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `answer`
--

INSERT INTO `answer` (`QuestionNo`, `StoreType`, `ItemName`, `CustomerName`, `Question`, `Answer`) VALUES
(1, 'SkinCare', 'Soap', 'Thuhini Lourdes', 'Can i buy more than 1000', 'Yes Madam definitely you can. But You have to Make the order before 1 week of the delivery date. For more details contact 0717005121');

-- --------------------------------------------------------

--
-- Table structure for table `bathandbody`
--

CREATE TABLE `bathandbody` (
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `Discription` varchar(255) NOT NULL,
  `Price` varchar(255) NOT NULL,
  `Image` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `customerorders`
--

CREATE TABLE `customerorders` (
  `OrderNo` int(11) NOT NULL,
  `StoreType` varchar(255) NOT NULL,
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `CustomerName` varchar(255) NOT NULL,
  `CustomerEmail` varchar(255) NOT NULL,
  `ContactNo` varchar(255) NOT NULL,
  `Address` varchar(255) NOT NULL,
  `Quantity` varchar(255) NOT NULL,
  `Payment` varchar(100) NOT NULL,
  `status` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customerorders`
--

INSERT INTO `customerorders` (`OrderNo`, `StoreType`, `ItemCode`, `ItemName`, `CustomerName`, `CustomerEmail`, `ContactNo`, `Address`, `Quantity`, `Payment`, `status`) VALUES
(2, 'SkinCare', 'S001', 'Soap', 'Thuhini', 'admin@gmail.com', '0717005121', 'Weligama', '4', '1000', 1),
(3, 'SkinCare', 'S002', 'Shampoo', 'Wathsara Daluwatta', 'wvd.51461@gmail.com', '0717005121', 'Weligama', '4', '5000', 1);

-- --------------------------------------------------------

--
-- Table structure for table `fragrance`
--

CREATE TABLE `fragrance` (
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `Discription` varchar(255) NOT NULL,
  `Price` varchar(255) NOT NULL,
  `Image` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `hair`
--

CREATE TABLE `hair` (
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `Discription` varchar(255) NOT NULL,
  `Price` varchar(255) NOT NULL,
  `Image` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `makeup`
--

CREATE TABLE `makeup` (
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `Discription` varchar(255) NOT NULL,
  `Price` varchar(255) NOT NULL,
  `Image` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `men`
--

CREATE TABLE `men` (
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `Discription` varchar(255) NOT NULL,
  `Price` varchar(255) NOT NULL,
  `Image` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `men`
--

INSERT INTO `men` (`ItemCode`, `ItemName`, `Discription`, `Price`, `Image`) VALUES
('s', 's', 's', 's', 'ant(1).png');

-- --------------------------------------------------------

--
-- Table structure for table `question`
--

CREATE TABLE `question` (
  `QuestionNo` int(11) NOT NULL,
  `StoreType` varchar(255) NOT NULL,
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `CustomerName` varchar(255) NOT NULL,
  `CustomerEmail` varchar(255) NOT NULL,
  `Question` varchar(255) NOT NULL,
  `status` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `question`
--

INSERT INTO `question` (`QuestionNo`, `StoreType`, `ItemCode`, `ItemName`, `CustomerName`, `CustomerEmail`, `Question`, `status`) VALUES
(1, 'SkinCare', 'S001', 'Soap', 'Thuhini Lourdes', 'm.thuhinilourdes@gmail.com', 'Can i buy more than 1000', 1),
(2, 'Men', 's', 's', 'Thuhini Lourdes', 'm.thuhinilourdes@gmail.com', 'Can i make the the price affordable', 0);

-- --------------------------------------------------------

--
-- Table structure for table `skin`
--

CREATE TABLE `skin` (
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `Discription` varchar(255) NOT NULL,
  `Price` varchar(255) NOT NULL,
  `Image` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `skin`
--

INSERT INTO `skin` (`ItemCode`, `ItemName`, `Discription`, `Price`, `Image`) VALUES
('S001', 'Soap', 'Good for Health and body', '250.00', 'rsz_muffin.png'),
('S002', 'Shampoo', 'Good for hair', '1250.00', 'ice-cream.png');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `Id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`Id`, `name`, `email`, `password`, `type`) VALUES
(1, 'Thuhini', 'admin@gmail.com', '111111', 'Admin'),
(2, 'Wathsara Daluwatta', 'wvd.51461@gmail.com', '111111', 'Customer'),
(3, 'Thuhini Lourdes', 'm.thuhinilourdes@gmail.com', '111111', 'Customer');

-- --------------------------------------------------------

--
-- Table structure for table `wellness`
--

CREATE TABLE `wellness` (
  `ItemCode` varchar(255) NOT NULL,
  `ItemName` varchar(255) NOT NULL,
  `Discription` varchar(255) NOT NULL,
  `Price` varchar(255) NOT NULL,
  `Image` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `answer`
--
ALTER TABLE `answer`
  ADD PRIMARY KEY (`QuestionNo`);

--
-- Indexes for table `bathandbody`
--
ALTER TABLE `bathandbody`
  ADD PRIMARY KEY (`ItemCode`);

--
-- Indexes for table `customerorders`
--
ALTER TABLE `customerorders`
  ADD PRIMARY KEY (`OrderNo`);

--
-- Indexes for table `fragrance`
--
ALTER TABLE `fragrance`
  ADD PRIMARY KEY (`ItemCode`);

--
-- Indexes for table `hair`
--
ALTER TABLE `hair`
  ADD PRIMARY KEY (`ItemCode`);

--
-- Indexes for table `makeup`
--
ALTER TABLE `makeup`
  ADD PRIMARY KEY (`ItemCode`);

--
-- Indexes for table `men`
--
ALTER TABLE `men`
  ADD PRIMARY KEY (`ItemCode`);

--
-- Indexes for table `question`
--
ALTER TABLE `question`
  ADD PRIMARY KEY (`QuestionNo`);

--
-- Indexes for table `skin`
--
ALTER TABLE `skin`
  ADD PRIMARY KEY (`ItemCode`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`Id`);

--
-- Indexes for table `wellness`
--
ALTER TABLE `wellness`
  ADD PRIMARY KEY (`ItemCode`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `customerorders`
--
ALTER TABLE `customerorders`
  MODIFY `OrderNo` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `question`
--
ALTER TABLE `question`
  MODIFY `QuestionNo` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `Id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
