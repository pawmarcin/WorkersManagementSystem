-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema relacja
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema relacja
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `relacja` DEFAULT CHARACTER SET utf8mb4 ;
USE `relacja` ;

-- -----------------------------------------------------
-- Table `relacja`.`slownik_interpretacji`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`slownik_interpretacji` (
  `id_slownik_interpretacji` INT(11) NOT NULL,
  `id_obserwacji` INT(11) NOT NULL,
  `id_analityka` INT(11) NOT NULL,
  `wartosc_interpretacji` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`id_slownik_interpretacji`),
  UNIQUE INDEX `id_slownik_interpretacji_UNIQUE` (`id_slownik_interpretacji` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`slownik_klasyfikacji`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`slownik_klasyfikacji` (
  `id_klasyfikacji` INT(11) NOT NULL,
  `id_obserwacji` INT(11) NOT NULL,
  `id_analityka` INT(11) NOT NULL,
  `wartosc_klasyfikacji` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`id_klasyfikacji`),
  UNIQUE INDEX `Id_klasyfikacji_UNIQUE` (`id_klasyfikacji` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`rejestr_obserwacji`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`rejestr_obserwacji` (
  `id_obserwacji` INT(11) NOT NULL,
  `id_obserwatora` INT(11) NOT NULL,
  `data_obserwacji` DATE NOT NULL,
  `godzina_obserwacji` TIME NOT NULL,
  `wspolrzedne_gps_zjawiska` VARCHAR(255) NOT NULL,
  `opis_zjawiska` VARCHAR(255) NOT NULL,
  `nazwa_katalogu_z_materialem_obserwacyjnym` VARCHAR(60) NOT NULL,
  `poziom_uprawnien_dostepu` TINYINT(4) NOT NULL,
  `kartoteka_obserwatorow_id_obserwatora` INT(11) NOT NULL,
  `slownik_interpretacji_id_slownik_interpretacji` INT(11) NOT NULL,
  `slownik_klasyfikacji_id_klasyfikacji` INT(11) NOT NULL,
  PRIMARY KEY (`id_obserwacji`, `kartoteka_obserwatorow_id_obserwatora`, `slownik_interpretacji_id_slownik_interpretacji`, `slownik_klasyfikacji_id_klasyfikacji`),
  UNIQUE INDEX `id_obserwacji_UNIQUE` (`id_obserwacji` ASC),
  UNIQUE INDEX `id_obserwatora_UNIQUE` (`id_obserwatora` ASC),
  UNIQUE INDEX `poziom_uprawnien_dostepu_UNIQUE` (`poziom_uprawnien_dostepu` ASC),
  INDEX `fk_rejestr_obserwacji_slownik_interpretacji1_idx` (`slownik_interpretacji_id_slownik_interpretacji` ASC),
  INDEX `fk_rejestr_obserwacji_slownik_klasyfikacji1_idx` (`slownik_klasyfikacji_id_klasyfikacji` ASC),
  CONSTRAINT `fk_rejestr_obserwacji_slownik_interpretacji1`
    FOREIGN KEY (`slownik_interpretacji_id_slownik_interpretacji`)
    REFERENCES `relacja`.`slownik_interpretacji` (`id_slownik_interpretacji`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_rejestr_obserwacji_slownik_klasyfikacji1`
    FOREIGN KEY (`slownik_klasyfikacji_id_klasyfikacji`)
    REFERENCES `relacja`.`slownik_klasyfikacji` (`id_klasyfikacji`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`analizy`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`analizy` (
  `id_analityka` INT(11) NOT NULL,
  `id_analizowanej_obserwacji` INT(11) NOT NULL,
  `data_wprowadzenia_zapisu` DATE NOT NULL,
  `opis_analizy` VARCHAR(255) NOT NULL,
  `wnioski_z_analizy` VARCHAR(255) NOT NULL,
  `klasyfikacja_zjawiska` VARCHAR(30) NOT NULL,
  `interpretacja_zjawiska` VARCHAR(255) NOT NULL,
  `r_obserwacji_id_obserwacji` INT(11) NOT NULL,
  `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` INT(11) NOT NULL,
  `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` INT(11) NOT NULL,
  `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji` INT(11) NOT NULL,
  PRIMARY KEY (`id_analityka`, `r_obserwacji_id_obserwacji`, `r_obserwacji_kartoteka_obserwatorow_id_obserwatora`, `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji`, `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji`),
  UNIQUE INDEX `id_analityka_UNIQUE` (`id_analityka` ASC),
  UNIQUE INDEX `id_analizowanej_obserwacji_UNIQUE` (`id_analizowanej_obserwacji` ASC),
  INDEX `fk_analizy_rejestr_obserwacji1_idx` (`r_obserwacji_id_obserwacji` ASC, `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` ASC, `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` ASC, `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji` ASC),
  CONSTRAINT `fk_analizy_rejestr_obserwacji1`
    FOREIGN KEY (`r_obserwacji_id_obserwacji` , `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` , `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` , `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji`)
    REFERENCES `relacja`.`rejestr_obserwacji` (`id_obserwacji` , `kartoteka_obserwatorow_id_obserwatora` , `slownik_interpretacji_id_slownik_interpretacji` , `slownik_klasyfikacji_id_klasyfikacji`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`kartoteka_uzytkownikow`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`kartoteka_uzytkownikow` (
  `id_uzytkownika` INT(11) NOT NULL AUTO_INCREMENT,
  `email` VARCHAR(250) NOT NULL,
  `haslo` VARCHAR(150) NOT NULL,
  `imie` VARCHAR(150) NOT NULL,
  `nazwisko` VARCHAR(150) NOT NULL,
  `rola` VARCHAR(150) NOT NULL,
  `data_rejestracji` DATE NOT NULL,
  `adres` LONGTEXT NOT NULL,
  `numer_telefonu` INT(11) NOT NULL,
  `uprawnienia_dostepu` TINYINT(1) NOT NULL DEFAULT 0,
  UNIQUE INDEX `email_UNIQUE` (`email` ASC),
  UNIQUE INDEX `numer_telefonu_UNIQUE` (`numer_telefonu` ASC),
  PRIMARY KEY (`id_uzytkownika`),
  UNIQUE INDEX `id_uzytkownika_UNIQUE` (`id_uzytkownika` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`dziennik_aktywnosci`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`dziennik_aktywnosci` (
  `id_dziennik_aktywnosci` INT(11) NOT NULL,
  `email_uzytkownika` MEDIUMTEXT NOT NULL,
  `czas_wejscia` TIME NOT NULL,
  `czas_wyjscia` TIME NOT NULL,
  `uruchamiane_funkcje` LONGTEXT NOT NULL,
  `informacje_o_wykonanej_akcji` LONGTEXT NOT NULL,
  `kartoteka_uzytkownikow_email` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`id_dziennik_aktywnosci`, `kartoteka_uzytkownikow_email`),
  UNIQUE INDEX `id_dziennik_aktywnosci_UNIQUE` (`id_dziennik_aktywnosci` ASC),
  INDEX `fk_dziennik_aktywnosci_kartoteka_uzytkownikow1_idx` (`kartoteka_uzytkownikow_email` ASC),
  CONSTRAINT `fk_dziennik_aktywnosci_kartoteka_uzytkownikow1`
    FOREIGN KEY (`kartoteka_uzytkownikow_email`)
    REFERENCES `relacja`.`kartoteka_uzytkownikow` (`email`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`wnioski_o_dostep`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`wnioski_o_dostep` (
  `id_wniosku` INT(11) NOT NULL,
  `email_uzytkownika` INT(30) NOT NULL,
  `rola` VARCHAR(100) NOT NULL,
  `uprawnienia_dostepu` VARCHAR(45) NOT NULL,
  `dziennik_aktywnosci_id_dziennik_aktywnosci` INT(11) NOT NULL,
  `dziennik_aktywnosci_kartoteka_uzytkownikow_email` VARCHAR(50) NOT NULL,
  `kartoteka_uzytkownikow_email` VARCHAR(30) NOT NULL,
  PRIMARY KEY (`id_wniosku`, `dziennik_aktywnosci_id_dziennik_aktywnosci`, `dziennik_aktywnosci_kartoteka_uzytkownikow_email`, `kartoteka_uzytkownikow_email`),
  UNIQUE INDEX `id_wniosku_UNIQUE` (`id_wniosku` ASC),
  INDEX `fk_wnioski_o_dostep_dziennik_aktywnosci1_idx` (`dziennik_aktywnosci_id_dziennik_aktywnosci` ASC, `dziennik_aktywnosci_kartoteka_uzytkownikow_email` ASC),
  INDEX `fk_wnioski_o_dostep_kartoteka_uzytkownikow1_idx` (`kartoteka_uzytkownikow_email` ASC),
  CONSTRAINT `fk_wnioski_o_dostep_dziennik_aktywnosci1`
    FOREIGN KEY (`dziennik_aktywnosci_id_dziennik_aktywnosci` , `dziennik_aktywnosci_kartoteka_uzytkownikow_email`)
    REFERENCES `relacja`.`dziennik_aktywnosci` (`id_dziennik_aktywnosci` , `kartoteka_uzytkownikow_email`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_wnioski_o_dostep_kartoteka_uzytkownikow1`
    FOREIGN KEY (`kartoteka_uzytkownikow_email`)
    REFERENCES `relacja`.`kartoteka_uzytkownikow` (`email`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`analizy_has_slownik_klasyfikacji`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`analizy_has_slownik_klasyfikacji` (
  `analizy_id_analityka` INT(11) NOT NULL,
  `slownik_klasyfikacji_id_klasyfikacji` INT(11) NOT NULL,
  PRIMARY KEY (`analizy_id_analityka`, `slownik_klasyfikacji_id_klasyfikacji`),
  INDEX `fk_analizy_has_slownik_klasyfikacji_slownik_klasyfikacji1_idx` (`slownik_klasyfikacji_id_klasyfikacji` ASC),
  INDEX `fk_analizy_has_slownik_klasyfikacji_analizy1_idx` (`analizy_id_analityka` ASC),
  CONSTRAINT `fk_analizy_has_slownik_klasyfikacji_analizy1`
    FOREIGN KEY (`analizy_id_analityka`)
    REFERENCES `relacja`.`analizy` (`id_analityka`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_analizy_has_slownik_klasyfikacji_slownik_klasyfikacji1`
    FOREIGN KEY (`slownik_klasyfikacji_id_klasyfikacji`)
    REFERENCES `relacja`.`slownik_klasyfikacji` (`id_klasyfikacji`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`analizy_has_slownik_interpretacji`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`analizy_has_slownik_interpretacji` (
  `analizy_id_analityka` INT(11) NOT NULL,
  `slownik_interpretacji_id_slownik_interpretacji` INT(11) NOT NULL,
  PRIMARY KEY (`analizy_id_analityka`, `slownik_interpretacji_id_slownik_interpretacji`),
  INDEX `fk_analizy_has_slownik_interpretacji_slownik_interpretacji1_idx` (`slownik_interpretacji_id_slownik_interpretacji` ASC),
  INDEX `fk_analizy_has_slownik_interpretacji_analizy1_idx` (`analizy_id_analityka` ASC),
  CONSTRAINT `fk_analizy_has_slownik_interpretacji_analizy1`
    FOREIGN KEY (`analizy_id_analityka`)
    REFERENCES `relacja`.`analizy` (`id_analityka`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_analizy_has_slownik_interpretacji_slownik_interpretacji1`
    FOREIGN KEY (`slownik_interpretacji_id_slownik_interpretacji`)
    REFERENCES `relacja`.`slownik_interpretacji` (`id_slownik_interpretacji`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`wnioski_o_dostep_has_kartoteka_uzytkownikow`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`wnioski_o_dostep_has_kartoteka_uzytkownikow` (
  `wnioski_o_dostep_id_wniosku` INT(11) NOT NULL,
  `kartoteka_uzytkownikow_email` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`wnioski_o_dostep_id_wniosku`, `kartoteka_uzytkownikow_email`),
  INDEX `fk_wnioski_o_dostep_has_kartoteka_uzytkownikow_kartoteka_uz_idx` (`kartoteka_uzytkownikow_email` ASC),
  INDEX `fk_wnioski_o_dostep_has_kartoteka_uzytkownikow_wnioski_o_do_idx` (`wnioski_o_dostep_id_wniosku` ASC),
  CONSTRAINT `fk_wnioski_o_dostep_has_kartoteka_uzytkownikow_wnioski_o_dost1`
    FOREIGN KEY (`wnioski_o_dostep_id_wniosku`)
    REFERENCES `relacja`.`wnioski_o_dostep` (`id_wniosku`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_wnioski_o_dostep_has_kartoteka_uzytkownikow_kartoteka_uzyt1`
    FOREIGN KEY (`kartoteka_uzytkownikow_email`)
    REFERENCES `relacja`.`kartoteka_uzytkownikow` (`email`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`analizy_has_rejestr_obserwacji`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`analizy_has_rejestr_obserwacji` (
  `analizy_id_analityka` INT(11) NOT NULL,
  `r_obserwacji_id_obserwacji` INT(11) NOT NULL,
  `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` INT(11) NOT NULL,
  `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` INT(11) NOT NULL,
  `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji` INT(11) NOT NULL,
  PRIMARY KEY (`analizy_id_analityka`, `r_obserwacji_id_obserwacji`, `r_obserwacji_kartoteka_obserwatorow_id_obserwatora`, `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji`, `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji`),
  INDEX `fk_analizy_has_rejestr_obserwacji_rejestr_obserwacji1_idx` (`r_obserwacji_id_obserwacji` ASC, `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` ASC, `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` ASC, `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji` ASC),
  INDEX `fk_analizy_has_rejestr_obserwacji_analizy1_idx` (`analizy_id_analityka` ASC),
  CONSTRAINT `fk_analizy_has_rejestr_obserwacji_analizy1`
    FOREIGN KEY (`analizy_id_analityka`)
    REFERENCES `relacja`.`analizy` (`id_analityka`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_analizy_has_rejestr_obserwacji_rejestr_obserwacji1`
    FOREIGN KEY (`r_obserwacji_id_obserwacji` , `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` , `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` , `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji`)
    REFERENCES `relacja`.`rejestr_obserwacji` (`id_obserwacji` , `kartoteka_obserwatorow_id_obserwatora` , `slownik_interpretacji_id_slownik_interpretacji` , `slownik_klasyfikacji_id_klasyfikacji`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`analizy_has_rejestr_obserwacji1`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`analizy_has_rejestr_obserwacji1` (
  `analizy_id_analityka` INT(11) NOT NULL,
  `r_obserwacji_id_obserwacji` INT(11) NOT NULL,
  `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` INT(11) NOT NULL,
  `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` INT(11) NOT NULL,
  `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji` INT(11) NOT NULL,
  PRIMARY KEY (`analizy_id_analityka`, `r_obserwacji_id_obserwacji`, `r_obserwacji_kartoteka_obserwatorow_id_obserwatora`, `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji`, `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji`),
  INDEX `fk_analizy_has_rejestr_obserwacji1_rejestr_obserwacji1_idx` (`r_obserwacji_id_obserwacji` ASC, `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` ASC, `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` ASC, `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji` ASC),
  INDEX `fk_analizy_has_rejestr_obserwacji1_analizy1_idx` (`analizy_id_analityka` ASC),
  CONSTRAINT `fk_analizy_has_rejestr_obserwacji1_analizy1`
    FOREIGN KEY (`analizy_id_analityka`)
    REFERENCES `relacja`.`analizy` (`id_analityka`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_analizy_has_rejestr_obserwacji1_rejestr_obserwacji1`
    FOREIGN KEY (`r_obserwacji_id_obserwacji` , `r_obserwacji_kartoteka_obserwatorow_id_obserwatora` , `r_obserwacji_slownik_interpretacji_id_slownik_interpretacji` , `r_obserwacji_slownik_klasyfikacji_id_klasyfikacji`)
    REFERENCES `relacja`.`rejestr_obserwacji` (`id_obserwacji` , `kartoteka_obserwatorow_id_obserwatora` , `slownik_interpretacji_id_slownik_interpretacji` , `slownik_klasyfikacji_id_klasyfikacji`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `relacja`.`wnioski_o_dostep_has_kartoteka_uzytkownikow2`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `relacja`.`wnioski_o_dostep_has_kartoteka_uzytkownikow2` (
  `wnioski_o_dostep_id_wniosku` INT(11) NOT NULL,
  `kartoteka_uzytkownikow_email` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`wnioski_o_dostep_id_wniosku`, `kartoteka_uzytkownikow_email`),
  INDEX `fk_wnioski_o_dostep_has_kartoteka_uzytkownikow2_kartoteka_u_idx` (`kartoteka_uzytkownikow_email` ASC),
  INDEX `fk_wnioski_o_dostep_has_kartoteka_uzytkownikow2_wnioski_o_d_idx` (`wnioski_o_dostep_id_wniosku` ASC),
  CONSTRAINT `fk_wnioski_o_dostep_has_kartoteka_uzytkownikow2_wnioski_o_dos1`
    FOREIGN KEY (`wnioski_o_dostep_id_wniosku`)
    REFERENCES `relacja`.`wnioski_o_dostep` (`id_wniosku`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_wnioski_o_dostep_has_kartoteka_uzytkownikow2_kartoteka_uzy1`
    FOREIGN KEY (`kartoteka_uzytkownikow_email`)
    REFERENCES `relacja`.`kartoteka_uzytkownikow` (`email`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
